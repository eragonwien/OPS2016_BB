# OPS2016_BB
OPS Projekt Branch and Bound

Information über Assignment Problem Implementierung
===================================================

Contributor: Elzagalmi, Abebe

#Installation: 
=============
Nach dem Download des Programm-Folders, entpacken Sie diesen in ein Verzeichnis ihrer Wahl. 
Wechseln Sie nun in dieses Verzeichnis und verwenden den Befehl: 

g++ -Wall -o test --std=c++11 Testen.cpp 

Dies kompiliert das Programm. 
Sie starten das Programm nun mithilfe des Befehls:

./test 


#Verwendung:
===========

Nach dem Start des Programms gibt es zwei Möglichkeiten, Tabelle erstellen(1) oder Assignment berechnen(2).
Wählt man die erste Option, "Tabelle erstellen", wird ein File mit Testdaten für das Programm erstellt. 
Hierfür muss man zuerst einen Dateinamen angeben und anschließend wieviele Jobs bzw. Agenten vorhanden sein sollen. 

Entscheidet man sich für die zweite Option, "Assignment berechnen", 
kann man die zuvor erstellten Testdaten mithilfe des implementierten Branch and Bound Algorithmus lösen lassen. 
Hierfür gibt man einfach den Dateinamen der zuvor erstellten Datei an.
Der Pfad zum Textfile muss wie für das jeweilige OS üblich angegeben werden. 
Anschließend wird einem die Matrix mit dem Assignment-Problem ausgegeben 
und die dazugehörige optimale Verteilung und die optimalen Kosten. 

----------------------------------------------------------------

Format des Textfiles: Erste Zeile bestimmte den Grad der Matrix, d.h. bei der Angabe vom Wert 4 wird eine 4x4 Matrix erstellt. Ab der zweiten Zeile werden die Einträge in einer Tabelle geordnet, Einträge sind mit einem Leerzeichen voneinander getrennt.

Anzahl der Jobs: 5 ist der Standardwert(zwischen 1 und 1000 ist optimal), wenn ein ungueltiger Wert eingegeben wird, wird eine Exception geworfen.
