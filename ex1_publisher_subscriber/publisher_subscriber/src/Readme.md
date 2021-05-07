# Esercizio 1

Implementare un publisher che simula un set di sensori che comunicano la posizione di 6 giunti ad un subscriber.

## Messaggio utilizzato

A tale scopo è stato utilizzato un messaggio di tipo JointTrajectory.
Questo tipo di messaggio ha un array per contenere il nome dei giunti, e un altro array che contiene oggetti di tipo JointTrajectoryPoint (di questi oggetti è stato utilizzato soltanto il campo positions[] per descrivere la posizione del giunto nelle 3 coordinate X,Y e Z).

JointTrajectory: http://docs.ros.org/en/melodic/api/trajectory_msgs/html/msg/JointTrajectory.html
JointTrajectoryPoint: http://docs.ros.org/en/melodic/api/trajectory_msgs/html/msg/JointTrajectoryPoint.html

## Publisher

Il publisher invia periodicamente sul topic "sensor_data" nome e posizione dei giunti.

## Subscriber

Il subscriber legge il messaggio dal topic "sensor_data" e stampa in output nome e posizione dei 6 giunti.