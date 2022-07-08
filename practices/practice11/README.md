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

```
----------------------------Output-----------------------------
Ability_Name:            Ability_Description:                                        Level:         Damage:        
Speak                    Use a speaker to tell people be like a bunny.               20             10
Flood                    Use Flood can washout animals.                              10             60
Fire                     Use Fire can burn down trees.                               5              90


Hide                     Become invisible for 4 seconds.                             15             30
Flood                    Use Flood can washout animals.                              20             22
Fire                     Use Fire can burn down trees.                               5              90


==> Update ability data

User gold: 199992

Ability_Name:            Ability_Description:                                        Level:         Damage:
Kong Fu                  Have the ability to fight ninja fox on a 12 ft tall tree.   10             60
Hide                     Become invisible for 4 seconds.                             17             30
Flood                    Use Flood can washout animals.                              20             42
Fire                     Use Fire can burn down trees.                               7              90


---------------------------------------------------------------
```

Delete docker image:
```
docker image rm practice11
```
