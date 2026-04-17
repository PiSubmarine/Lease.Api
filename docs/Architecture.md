# Session.Api Architecture

`PiSubmarine.Session.Api` defines the protocol-independent domain vocabulary for session and lease coordination.

The module intentionally does not describe gRPC, HTTP, UDP, RTP, or GStreamer. Those are adapter concerns.

## Goals

- Keep session business logic independent from its external protocol.
- Keep stream modules independent from session arbitration details.
- Allow resources to register themselves with generic lease policies.
- Separate lease grant from resource-specific connection activation.

## Core Concepts

### Resource

A resource is any component that wants session-based access control.

Examples:

- control input
- telemetry stream
- video stream

The meaning of a resource is defined by its owner, not by the session manager.

### Lease

A lease is a time-bounded grant that allows one session to access one resource.

Leases:

- are acquired explicitly
- expire unless renewed
- may be released explicitly
- are validated by resource owners before activation or use

### Lease Policy

The first version of the API keeps policy intentionally small:

- `Exclusive`: at most one active lease holder
- `Shared`: multiple active lease holders
- `MaxLeases`: optional upper bound for shared resources
- `LeaseDuration`
- `HeartbeatTimeout`
- `RequiresActivation`

This keeps the API generic without introducing stream-specific roles such as operator or viewer.

### Activation

Connection negotiation is not part of the session manager.

The session manager grants a lease and may publish an opaque activation descriptor for the resource. The resource owner
defines how that descriptor is used.

Example flow:

1. A client requests a lease for `video-main`.
2. The session manager grants the lease and returns the resource's activation descriptor.
3. The client contacts the video component directly.
4. The video component validates the lease.
5. The video component performs transport-specific negotiation, such as adding a new RTP sink.

This keeps the session manager agnostic to transport details while still allowing components to expose activation
endpoints.

## Intended Layering

- `Session.Api`: domain types and abstract interfaces
- `Session`: lease and resource registration business logic
- `Session.Grpc` or `Session.Http`: protocol adapters
- `Control.*`, `Telemetry.*`, `Video.*`: resource owners and transport implementations

Dependencies should point inward toward `Session.Api`, never toward a specific session protocol adapter.

## Interface Segregation

The API is split into narrow ports so components depend only on the operations they actually use.

- `IResourceRegistry`
  Used by resource owners such as control, telemetry, and video during startup.
- `ILeaseValidator`
  Used by resource owners at runtime before accepting a resource-specific activation or packet stream.
- `ILeaseIssuer`
  Used by client-facing session adapters that acquire, renew, and release leases.
