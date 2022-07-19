First: ```git clone https://github.com/jerryli99/summer2022_cpp.git```

or ```cd summer2022_cpp``` and then do a ```git pull```

Next:
```
cd summer2022_cpp/practices/practice11
```

Change permission:
```
chmod u+x script.sh
```

To run code, do the following: (I assume you have Docker installed)
```bash
./script.sh
```
## Update
# Reduced docker build image size from ~1.27GB to ~185MB 

```
----------------------------Output-----------------------------
Part 1:

1000111011
571
-------------------------------------------------------------
Part 2:

Normal queue with default capacity 8
1
2
3
4
5
6
7
8
Dequeue(): 1
Peek(): 2
Dequeue(): 2
Dequeue(): 3
Dequeue(): 4
Peek(): 5
Dequeue(): 5
Dequeue(): 6
Dequeue(): 7
Dequeue(): 8
Empty Queue.
Queue size: 0
Calling destructor from Queue.


Circular Queue with default capacity 8
Peek(): 1
Dequeue(): 1
Dequeue(): 2
Peek(): 3
Updated queue
9
10
3
4
5
6
7
8
Circular Queue size: 8
Calling destructor from CricularQueue.

Calling destructor from Queue.



-------------------------------------------------------------
Part 3:

Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 John
 johneie123@gmail.com
 975-222-3333
 10-4'x6'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 John
 johneie123@gmail.com
 975-222-1033
 20-8'x10'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 John
 johneie123@gmail.com
 975-222-5958
 3-8'x11'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 Berry
 berry222@yahoo.com
 745-222-1356
 28-4'x6'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 Kolin
 kolin@gmail.com
 301-252-6333
 9-4'x6'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 Mary
 maryling@yahoo.com
 202-222-0125
 2-8'x10'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 Lin
 Lin-yyu0101@gmail.com
 301-251-4561
 30-4'x6'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 Nacy
 Nancy999@yahoo.com
 202-331-7979
 1-8'x10'
}


Vendor worker is now processing orders...
Sending back to the CVS store.

Completed!

CVS store 5674 import Photo Queue:
Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 John
 johneie123@gmail.com
 975-222-3333
 10-4'x6'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 John
 johneie123@gmail.com
 975-222-1033
 20-8'x10'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 John
 johneie123@gmail.com
 975-222-5958
 3-8'x11'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 Berry
 berry222@yahoo.com
 745-222-1356
 28-4'x6'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 Kolin
 kolin@gmail.com
 301-252-6333
 9-4'x6'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 Mary
 maryling@yahoo.com
 202-222-0125
 2-8'x10'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 Lin
 Lin-yyu0101@gmail.com
 301-251-4561
 30-4'x6'
}


Store id: 5674
Vendor id: GM646KW9
Customer info:
{
 Nacy
 Nancy999@yahoo.com
 202-331-7979
 1-8'x10'
}
---------------------------------------------------------------
```

Delete docker image:
```
docker image rm practice12
```
