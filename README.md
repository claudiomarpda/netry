# netry

<h4>Netry is a very simple high level networking library implementation of The Single UNIX Specification, Version 2. </h4>

<h2>Project</h2>

* Language: C++ 11 Standard
* IDE: CLion 2017.2.3
* Build: CMake 3.9

<h3>Functionality</h3>

* Server instance to wait for connections in a specific port.
* Socket instance to connect in a specific ip address and port.
* Data transfer between two endpoints using a connected socket for the types:
    * Byte
    * Integer
    * String
    

<h2>Class Diagram</h2>

![alt tag](https://github.com/claudiomarpda/netry/blob/master/img/netry_class_diagram.png)


<h2>Possible Improvements</h2>

<p>Allow listening in more than one port with the same ip address.<br>
The sockaddr_in C struct can be initiated only once with one address, so when a new ServerSocket is instantiated, it throws an error.</p>
<p>Solutions: </p>  

* Keep a reference to every struct address <i>sockaddr_in</i> and, if it alreadt exists, use it to listen in a new port.<br>
* Handle it in C level
 
<h2>Reference</h2>

http://pubs.opengroup.org/onlinepubs/7908799/xnsix.html