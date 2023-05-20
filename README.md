# Philosophers_42
- Intorduction <br>
what is this project talk about ?<br>
The philosopher task is a task that directly implements the "eating philosopher problem", each philosopher reprsent a thread, so what is a thread ?<br>
a thread refers to a squence of instractions that can be executed within a program. the threads are enable the execution of multiple tasks concurrently. <br>
so how we can creat a thread?
in C, threads can be created by using the threading library,(pthread)library, wich providee functions for thread creation.<br>
we use this function to create the thread :
<img width="1314" alt="Screen Shot 2023-05-20 at 5 39 57 AM" src="https://github.com/hachahbo/Philosophers_42/assets/116384287/2207fa8a-a66b-4065-bc5d-3cf9d086fce0">
<br>
<h4> Before we dive further , i have to explane what is the relation between threads and processes  : <h4><br>

![thread vs process](https://github.com/hachahbo/Philosophers_42/assets/116384287/4e01bcde-eea7-4925-af0c-103f5669d060)
  
 Threads and processes are related in the sense that threads are typically created within a process and operate within the context of that process. Here are some important aspects of their relationship .<br>
  A process can have one or more threads of execution. Threads are lightweight units of execution that operate within the context of a process. They share the same memory space, file descriptors, and other resources of the parent process. <br>
  we can create multi threads from one process and And vice versa is wrong.<br> 
  Since threads within a process share the same memory space and resources, they can easily communicate and share data with each other.
  
  ok!! so let's continue the explination of this project . <br>
  we have hre an image refers to the subject theorem :
  
<img width="912" alt="Screen Shot 2023-05-20 at 9 33 34 AM" src="https://github.com/hachahbo/Philosophers_42/assets/116384287/671c2150-d04a-4f63-b057-25e7deffd954">

  
