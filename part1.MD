# PRÀCTICA 4: Sistemes Operatius en Temps Real (FreeRTOS)
## Apartat 1: Introducció a la Multitarea

### Objectiu
Comprendre el funcionament bàsic d'un sistema operatiu en temps real (RTOS) mitjançant la generació de tasques que divideixen el temps d'ús de la CPU en un ESP32.

### Descripció de l'exercici
En aquest primer exercici, s'ha programat un codi que executa dues tasques de manera simultània utilitzant el planificador de FreeRTOS[cite: 162, 163]:

1. **Task Principal (`loop`)**: Executada per l'Arduino ESP32 `loopTask`. Imprimeix el missatge `"this is ESP32 Task"` cada segon.
2. **Task Addicional (`anotherTask`)**: Creada manualment amb la funció `xTaskCreate`. Imprimeix el missatge `"this is another Task"` cada segon.

### Sortida pel Port Sèrie
Al monitor sèrie (115200 bps) s'observa com els missatges s'alternen, demostrant que el processador va saltant d'una tasca a l'altra:

```text
this is ESP32 Task
this is another Task
this is ESP32 Task
this is another Task
...
