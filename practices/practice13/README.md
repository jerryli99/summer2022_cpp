First: ```git clone https://github.com/jerryli99/summer2022_cpp.git```

or ```cd summer2022_cpp``` and then do a ```git pull```

Next:
```
cd summer2022_cpp/practices/practice13
```

Change permission:
```
chmod u+x script.sh
```

To run code, do the following: (I assume you have Docker installed)
```bash
./script.sh
```

```
----------------------------Output-----------------------------
Add nodes: 1, 2, 3 to linkedlist
1-->2-->3-->nullptr

Delete the front node: 
UniDirNode delete
Node delete
2-->3-->nullptr

Add front node: 4
Contains 4?
1
Remove the end node
UniDirNode delete
Node delete
4-->2-->nullptr

Delete linkedlist
UniDirNode delete
Node delete
UniDirNode delete
Node delete
---------------------------------------------------------------
```

Delete docker image:
```
docker image rm practice13
```
