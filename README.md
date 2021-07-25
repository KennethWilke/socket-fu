# Socket-fu

It's been probably 2 years since I've last done some socket programming in C. I can recall a majority of the APIs and how I want to go about using them, but refreshing and putting all of that together can take some time and I found myself wanting a nice clean basis to use for socket programming. To fulfill that desire, I've decided to create a small series of example programs that I can use as a starting place for future socket programming work. Those examples will live here!

These examples will be geared towards usage on Linux. The simpler examples should work find on other operating systems, but I'll be using [epoll()](https://www.suchprogramming.com/epoll-in-3-easy-steps/) pretty quickly after.

## Goals

These are the types of examples I'm intending to make, though nothing exists quite yet!

- [x] [A simple TCP Server base](01-simple)
- [ ] A TCP server that forks processes for each connection
- [ ] A single-threaded, asynchronous TCP server that uses `select`
- [ ] A single-threaded, asynchronous TCP server that uses `epoll`
