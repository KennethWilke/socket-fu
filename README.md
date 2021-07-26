# Socket fu

I always forget 

These examples will be geared towards usage on Linux. The simpler examples should work find on other operating systems, but I'll be using [epoll()](https://www.suchprogramming.com/epoll-in-3-easy-steps/) pretty quickly after.

## Goals

These are the types of examples I'm intending to make, though nothing exists quite yet!

- [x] [A simple TCP Server base](01-simple)
- [ ] [A TCP server that forks processes for each connection](02-forked)
- [ ] A single-threaded, asynchronous TCP server that uses `select`
- [ ] A single-threaded, asynchronous TCP server that uses `epoll`
