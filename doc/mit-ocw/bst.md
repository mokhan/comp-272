# Scheduling & Binary Search Trees

* Airport with a single runway.
* Reservations for future landings.
* Reserve request specifies landing time t
* Add `t` to the set `R` of landing times if no other landings are scheduled within `k` minutes.
* Remove from set `R` after plane lands.
* `|R| = n`
* `O(lg n)` time where `n` is the size of the set.
