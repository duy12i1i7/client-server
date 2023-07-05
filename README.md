# Harness the power of parallel computing by building an application that runs on multiple machines using the master-workers model and lightning-fast TCP communication.

This project is written in C/C++.

## Overview
Building a parallel computing application on multiple machines using the master-workers model and TCP communication is a challenging and exciting topic. In this model, the controller server is responsible for dividing the work among the worker machines and managing parallel computation on multiple machines. The TCP communication protocol ensures reliability and security in data exchange between machines.

With the development of technology, building parallel computing applications on multiple machines is becoming increasingly popular and necessary. This helps to speed up data processing and solve complex problems more efficiently. The master-workers model also brings other benefits, such as scalability, flexibility, and ease of management.

Building a parallel computing application on multiple machines using the master-workers model and TCP communication is a field full of potential and can bring many benefits to users. It is a topic worth exploring and researching further.

## What is the parallel computation?
Parallel computing is a type of computation in which many calculations or processes are carried out simultaneously. It involves breaking down more significant problems into smaller, independent, often similar parts that can be executed simultaneously by multiple processors communicating via shared memory. The results of these smaller parts are then combined upon completion as part of an overall algorithm.

Several forms of parallel computing exist, including bit-level, instruction-level, data, and task parallelism. Parallel computing has long been employed in high-performance computing but has gained broader interest due to the physical constraints preventing frequency scaling. As power consumption by computers has become a concern in recent years, parallel computing has become the dominant paradigm in computer architecture, mainly in multi-core processors.

Parallel computing can speed up data processing and solve complex problems more efficiently. It also brings other benefits, such as scalability, flexibility, and ease of management. It is a field full of potential and can benefit users.

## What is a master-worker model?

The master-worker model, the master-slave or the map-reduce pattern, is used for parallel processing. It follows a simple approach that allows applications to perform simultaneous processing across multiple machines or processes via a master and multiple workers.

In this model, nodes can be classified into two distinct groups, namely, masters and workers. Worker nodes' fundamental responsibility is performing compute-intensive tasks such as video transcoding, training large-scale neural networks with millions of parameters, calculating Online Analytical Processing (OLAP) queries, running a Continuous Integration (CI) pipeline, or executing map-reduce operations on massive datasets.

On the other hand, controller nodes are typically assigned the role of the coordinator. They are responsible for discovering and keeping track of available worker nodes, breaking down jobs into smaller tasks and distributing them to each worker node.

The master-worker model is a commonly used pattern for building distributed systems that have been around practically forever. It allows for efficient parallel processing, speeds up data processing, and solves complex problems more efficiently.

## What is the TCP connection?
TCP, or Transmission Control Protocol, is one of the main protocols of the Internet protocol suite. It lies between the Application and Network Layers and provides reliable delivery services. It is a connection-oriented communication protocol that helps exchange messages between different devices over a network.

TCP works with the Internet Protocol (IP), which establishes the technique for sending data packets between computers. To ensure that each message reaches its target location intact, the TCP/IP model breaks down the data into small bundles and reassembles them into the original message on the opposite end. Sending the information in small data bundles makes it easier to maintain efficiency than sending everything in one go.

TCP is a stateful protocol and typically proceeds in an SYN-ACK-data-FIN sequence, or SYN/RST, in case of a rejected transmission. Both peers maintain a status of the connection (handshake, established, closing, closed). TCP allows transmitting information in both directions and provides features such as a segment numbering system, flow control, error control, and full duplex.

## Why Do we want to use this connection?
TCP (Transmission Control Protocol) is a reliable, connection-oriented protocol with several benefits over other transport layer protocols, such as UDP (User Datagram Protocol). Some reasons why you might choose to use TCP include:

Reliability: TCP provides reliable, ordered, and error-checked data delivery between applications running on hosts communicating via an IP network. It uses several mechanisms, such as retransmission, flow control, and error detection, to ensure that data is transmitted reliably.

Connection-oriented: TCP is a connection-oriented protocol, meaning a connection between the client and server must be established before data can be sent. This allows for efficient transmission of data and ensures that data is delivered in the correct order.

Congestion control: TCP employs congestion avoidance mechanisms to prevent congestion and ensure efficient data transmission.

Widely used: TCP is one of the main protocols of the Internet protocol suite and is widely used by major Internet applications such as the World Wide Web, email, remote administration, and file transfer.

TCP is a good choice when data reliability and ordered delivery are essential considerations.

## Architecture of TCP connection protocol and UDP connection protocol
### TCP connection protocol
![architecture of TCP connection protocol](https://topdev.vn/blog/wp-content/uploads/2020/10/Socket-tcp.png)

### UDP connection protocol
![architecture of UDP connection protocol](https://topdev.vn/blog/wp-content/uploads/2020/10/Socket-udp.png) 

## Describe the project.
This problem aims to calculate the sum of the elements of a 9x9 matrix using the Master-Workers model in the C/C++ language. In this model, the central server (Master) will read the matrix from a text file and send each subordinate server (Worker) 3 rows of the matrix. Each Worker will calculate the sum of the elements received and return the result to the Master. Finally, the Master will aggregate the results from the Workers and calculate the sum of those results. The communication process between the Master and Worker uses the TCP protocol.

## Usage example 
On each `worker` and `master` folder, the execution file will be created. If you want to edit the configuration file for a different result, you can recreate the execution file using this command:


    gcc $(file.c) -o (execute_file) -lpthread

In which, `-lpthread` is an option of the `gcc` or `g++` compiler to link the program with the libpthread library. The `libpthread` library provides functions and data structures to create and manage `threads` in the program.

When you use functions from the `<pthread.h>` library in your program, you need to link the program with the `libpthread` library by adding the `-lpthread` option when compiling the program.

After that, To use this project, follow these steps:

### Prepare the matrix

The matrix data is stored in the `master` directory. If you want to use a different matrix, you can edit the `matrix.txt` file. 

Please don't forget that the matrix size is `9x9.`

### Opening the machine

To run each machine, please open four terminals. On each terminal, run each machine by using this command:

     ./$(execute_file)

#### Please note that you must run the `master` before running the `workers`.

### Watching the results on the terminal

Every process will be displayed on the terminal. Here you can see the results of the project.

## I hope this project is helpful to you. Thanks for reading this project. 
