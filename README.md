# About
An implementation of some process scheduling algorithms

### Instructions

#### Configuration
Before running the application, you need to create `.env` file at the root of
the project directory. For example, it can be done in Linux as shown below:

```
touch .env
```

In the `.env` file paste the following

```
TIME_QUANTUM=<time-quantum>
```

Change the value of 'time-quantum' as you wish


#### Execution
To build the executable, run the command
```
make
```

To run the executable, run the command
```
make run
```

To clean the executable and the object files, run the command
```
make clean
```
