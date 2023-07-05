# Harness the power of parallel computing by building an application that runs on multiple machines using the master-workers model and lightning-fast TCP communication.

This project is written by C/C++

## Overview
Building a parallel computing application on multiple machines using the master-workers model and TCP communication is a challenging and exciting topic. In this model, the master server is responsible for dividing the work among the worker machines and managing parallel computation on multiple machines. The use of the TCP communication protocol ensures reliability and security in data exchange between machines.

With the development of technology, building parallel computing applications on multiple machines is becoming increasingly popular and necessary. This helps to speed up data processing and solve complex problems more efficiently. The master-workers model also brings other benefits such as scalability, flexibility, and ease of management.

In general, building a parallel computing application on multiple machines using the master-workers model and TCP communication is a field full of potential and can bring many benefits to users. It is a topic worth exploring and researching further.

## What is the parallel computation?
Parallel computing is a type of computation in which many calculations or processes are carried out simultaneously. It involves breaking down larger problems into smaller, independent, often similar parts that can be executed simultaneously by multiple processors communicating via shared memory. The results of these smaller parts are then combined upon completion as part of an overall algorithm.

There are several different forms of parallel computing, including bit-level, instruction-level, data, and task parallelism. Parallel computing has long been employed in high-performance computing but has gained broader interest due to the physical constraints preventing frequency scaling. As power consumption by computers has become a concern in recent years, parallel computing has become the dominant paradigm in computer architecture, mainly in the form of multi-core processors.

Parallel computing can speed up data processing and solve complex problems more efficiently. It also brings other benefits such as scalability, flexibility, and ease of management. It is a field full of potential and can bring many benefits to users.

## What is a master-worker models?

The master-worker model, sometimes called the master-slave or the map-reduce pattern, is used for parallel processing. It follows a simple approach that allows applications to perform simultaneous processing across multiple machines or processes via a master and multiple workers.

In this model, nodes can be classified into two distinct groups, namely, masters and workers. The key responsibility of worker nodes is to perform compute-intensive tasks such as video transcoding, training large-scale neural networks with millions of parameters, calculating Online Analytical Processing (OLAP) queries, running a Continuous Integration (CI) pipeline, or executing map-reduce operations on massive datasets.

On the other hand, master nodes are typically assigned the role of the coordinator. They are responsible for discovering and keeping track of available worker nodes, breaking down jobs into smaller tasks and distributing them to each worker node.

The master-worker model is a commonly used pattern for building distributed systems that have been around for practically forever. It allows for efficient parallel processing and can speed up data processing and solve complex problems more efficiently.

## What is the TCP connection?
TCP, or Transmission Control Protocol, is one of the main protocols of the Internet protocol suite. It lies between the Application and Network Layers and is used in providing reliable delivery services. It is a connection-oriented protocol for communications that helps in the exchange of messages between different devices over a network.

TCP works with the Internet Protocol (IP), which establishes the technique for sending data packets between computers. To ensure that each message reaches its target location intact, the TCP/IP model breaks down the data into small bundles and then reassembles the bundles into the original message on the opposite end. Sending the information in small bundles of data makes it easier to maintain efficiency as opposed to sending everything in one go.

TCP is a stateful protocol and typically proceeds in a SYN-ACK-data-FIN sequence, or SYN/RST in case of a rejected transmission. Both peers maintain a status of the connection (handshake, established, closing, closed). TCP allows for the transmission of information in both directions and provides features such as segment numbering system, flow control, error control, and full duplex.

## Why Do we want to use this connection?
TCP (Transmission Control Protocol) is a reliable, connection-oriented protocol that provides several benefits over other transport layer protocols such as UDP (User Datagram Protocol). Some reasons why you might choose to use TCP include:

Reliability: TCP provides reliable, ordered, and error-checked delivery of data between applications running on hosts communicating via an IP network. It uses a number of mechanisms such as retransmission, flow control, and error detection to ensure that data is transmitted reliably.

Connection-oriented: TCP is a connection-oriented protocol, which means that a connection between the client and server must be established before data can be sent. This allows for efficient transmission of data and ensures that data is delivered in the correct order.

Congestion control: TCP employs network congestion avoidance mechanisms to prevent network congestion and ensure efficient transmission of data.

Widely used: TCP is one of the main protocols of the Internet protocol suite and is widely used by major internet applications such as the World Wide Web, email, remote administration, and file transfer.

Overall, TCP is a good choice when reliability and ordered delivery of data are important considerations.

## Architecture of TCP connection protocol and UDP connection protocol
### TCP connection protocol
![architecture of TCP connection protocol](https://topdev.vn/blog/wp-content/uploads/2020/10/Socket-tcp.png)

### UDP connection protocol
![architecture of UDP connection protocol](https://topdev.vn/blog/wp-content/uploads/2020/10/Socket-udp.png) 

## Describe the project.
The goal of this problem is to calculate the sum of the elements of a 9x9 matrix using the Master-Workers model in the C/C++ language. In this model, the main server (Master) will read the matrix from a text file and send each subordinate server (Worker) 3 rows of the matrix. Each Worker will calculate the sum of the elements received and send the result back to the Master. Finally, the Master will aggregate the results from the Workers and calculate the sum of those results. The communication process between Master and Worker uses the TCP protocol.

## Usage example 
On each `worker` and `master` folder, the execution file will be created. If you want to edit the configuration file for a different result, you can recreate the execution file using this command:


``` gcc $(file.c) -o (execute_file) -lpthread ```

In which, `-lpthread` is an option of the `gcc` or `g++` compiler to link the program with the libpthread library. The `libpthread` library provides functions and data structures to create and manage `threads` in the program.

When you use functions from the `<pthread.h>` library in your program, you need to link the program with the `libpthread` library by adding the `-lpthread` option when compiling the program.

Afterthat, To using this project, following these steps:

### Prepare the matrix

The matrix data is stored on the `master` directory. If you want to use the different matrix, you can edit the `matrix.txt` file. 

Please don't forget that the matrix size is `9x9`

### Opening the machine

To running each machine, please open 4 terminals. On each terminal, run each machine by using this command:

``` ./$(execute_file)```

#### Please note that you must running the `master` before running the `workers`.

### Watching the results on the terminal

Every process will be displayed on the terminal. Here you can see the results of the project.

## Hope that This project is helpful for you. Thanks for reading this project. 