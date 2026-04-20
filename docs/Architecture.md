# Lease.Api Architecture

`PiSubmarine.Lease.Api` defines the protocol-independent domain vocabulary for lease-based access coordination.

The module intentionally does not describe gRPC, HTTP, UDP, RTP, or GStreamer. Those are adapter concerns.

## Goals

- Keep lease business logic independent from its external protocol.
- Keep stream modules independent from lease arbitration details.
- Allow resources to register themselves with generic lease policies.
- Keep resource-specific connection setup outside the generic lease API.

## Core Concepts

### Resource

A resource is any component that wants lease-based access control.

Examples:

- control input
- telemetry stream
- video stream

The meaning of a resource is defined by its owner, not by the lease manager.

### Lease

A lease is a time-bounded grant that allows access to one resource.

Leases:

- are acquired explicitly
- expire unless renewed
- may be released explicitly
- are validated by resource owners before use

### Lease Policy

The first version of the API keeps policy intentionally small:

- `MaxLeases = 1`: exclusive access
- `MaxLeases = N > 1`: bounded shared access
- `MaxLeases = std::nullopt`: unlimited shared access
- `LeaseDuration`

This keeps the API generic without introducing stream-specific roles such as operator or viewer.

## Intended Layering

- `Lease.Api`: domain types and abstract interfaces
- lease implementation: lease and resource registration business logic
- protocol adapters such as gRPC or HTTP
- `Control.*`, `Telemetry.*`, `Video.*`: resource owners and transport implementations

Dependencies should point inward toward `Lease.Api`, never toward a specific protocol adapter.

## Interface Segregation

The API is split into narrow ports so components depend only on the operations they actually use.

- `IResourceRegistry`
  Used by resource owners such as control, telemetry, and video during startup.
- `ILeaseValidator`
  Used by resource owners at runtime before accepting packets or a resource-specific setup flow.
- `ILeaseIssuer`
  Used by client-facing protocol adapters that acquire, renew, and release leases.

## Errors

`Lease.Api` defines domain-specific `ErrorCode` values for lease failures such as invalid resource identifiers,
registration conflicts, lease limits, expiration, and secure lease id generation failures.
