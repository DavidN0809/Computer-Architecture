# Repo Moved 
https://github.com/Cameron29a/ECGR_5181

# Computer-Architecture
Assignments and Projects are broken into subfolders, description of each assignment and projects are below.

## HW1
1. Generate 20 events randomly. Each event E = (t, v) where t is time the event will be executed
and v is an integer value (randomly generated) for printing. You can get t from the system time.
2. Sort-insert () these events into a Master Event Queue (MEQ).
3. Write a function to read the top (earliest) event from MEQ, print its value v, generate a new
event E’ = (t’, v), where t’ = t + irand (v).
4. Sort-insert () the event E’ into MEQ.
5. Stop when 100 events have been processed from the MEQ.
Use C++ for coding, and implement the MEQ using Vectors.

## HW2
Implement a single threaded (no requirement of multi-threading) Event driven Simulator to execute the code segment for the complete “for loop” (code segment on pp.177 in textbook), including the last run of the loop when the predictively fetched instruction(s) from the front of the loop will have to be discarded, and the halt instruction executed.

1) Each stage of the pipeline must Print() the {stage_name, instruction_name, data, clock cycle number} that is being processed in each stage.
2) Print() the Event List contents for every clock cycle.
Assume: Register x1 initially has the value 160 and Register x2 has the fixed value 0 for the following code:
```assembly
Loop: fld f0,0(x1)
      fadd.d f4,f0,f2
      fsd f4,0(x1)
      addi x1,x1,-8
      bne x1,x2,Loop
```
[hw2 visual aide](https://docs.google.com/spreadsheets/d/1Fxm5tvVx8mPrK7fk1-Mhpuf3QoQkFx3j7917Vq06N0o/edit#gid=0)

In the above link an example of how the pipeline instructions should work and the value of x1
