# PRACTICA 4: Sistemes Operatius en Temps Real (FreeRTOS)

## Objectiu de la pràctica
L'objectiu principal d'aquest programa és comprendre el funcionament d'un sistema operatiu en temps real (RTOS) mitjançant la generació de tasques i la seva execució dividint el temps d'ús de la CPU.

## Descripció de l'Ejercicio Practico 2
Aquest programa implementa la sincronització de dues tasques independents que actuen sobre un mateix recurs (un LED al pin 4). Per evitar conflictes i assegurar un ordre, s'utilitza un **semàfor binari** com a mecanisme de sincronització.

### Components del Sistema

1. **Semàfor (`sem`)**: Actua com un "testimoni" o clau. Només la tasca que té el semàfor pot modificar l'estat del LED.
2. **Tasca d'Encedre (`tOn`)**:
   - Espera a que el semàfor estigui disponible.
   - Encén el LED (HIGH).
   - Bloqueja la seva execució durant 1 segon per permetre que altres tasques usin la CPU.
   - Allibera el semàfor per a la següent tasca.
3. **Tasca d'Apagar (`tOff`)**:
   - Espera a rebre el semàfor que ha deixat la tasca anterior.
   - Apaga el LED (LOW).
   - Bloqueja la seva execució durant 1 segon.
   - Allibera el semàfor i cedeix el torn.

### Funcionament del Programador (Scheduler)
En aquest exercici, ambdues tasques tenen la mateixa **prioritat (1)**. El planificador de FreeRTOS comparteix el temps de processament disponible entre elles[cite: 157]. L'ús de `vTaskDelay` és fonamental, ja que indica al programador que la tasca actual no ha d'executar-se durant un període determinat, permetent l'execució de la següent tasca en cua[cite: 45, 46].

## Esquema de connexió
| Component | Pin ESP32-S3 |
| :--- | :--- |
| LED (Ànode) | GPIO 4 |
| Resistència | 220 Ohms |
| Càtode | GND |