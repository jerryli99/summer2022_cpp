First: ```git clone https://github.com/jerryli99/summer2022_cpp.git```

or ```cd summer2022_cpp``` and then do a ```git pull```

Next:
```
git branches

git checkout practice13_modified1_branch

cd practices/practice13_modified1
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
2-->1-->3-->nullptr
Delete node.
Delete node.
Delete node.
All nodes removed from linkedlist.


[Item id: 9]-->[Item id: 8]-->[Item id: 7]-->[Item id: 6]-->[Item id: 5]-->[Item id: 4]-->[Item id: 3]-->[Item id: 2]-->[Item id: 1]-->[Item id: 0]-->nullptr
Does the linkedlist contains Item with id: 1? Yes
Delete node.
Delete node.
Delete node.
Delete node.
Delete node.
Delete node.
Delete node.
Delete node.
Delete node.
Delete node.
No nodes to remove.
No nodes to remove.
Does the linkedlist contains Item with id: 1? No
nullptr
All nodes removed from linkedlist.
---------------------------------------------------------------
```

Delete docker image:
```
docker image rm practice13_modified1
```
