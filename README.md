# Computer-Architecture
ECGR 5181
## HW1
Assignment 1
1. Generate 20 events randomly. Each event E = (t, v) where t is time the event will be executed
and v is an integer value (randomly generated) for printing. You can get t from the system time.
2. Sort-insert () these events into a Master Event Queue (MEQ).
3. Write a function to read the top (earliest) event from MEQ, print its value v, generate a new
event E’ = (t’, v), where t’ = t + irand (v).
4. Sort-insert () the event E’ into MEQ.
5. Stop when 100 events have been processed from the MEQ.
Use C++ for coding, and implement the MEQ using Vectors.
