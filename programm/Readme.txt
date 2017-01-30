Information über Assignment Problem Implementierung
===================================================

Contributor: Elzagalmi

#Verwendung:
===========
Kompilieren: Zum Kompilieren einfach mit dem C++ Compiler das Testen.cpp Datei in c++14 Kompilieren.
Zum Beispiel mit dem C++ Compiler: "g++ Testen.cpp -o Testen -std=c++14" eingeben.

Nach dem Start des Programms gibt es zwei Möglichkeiten, Tabelle erstellen oder Assignment berechnen, bei Eingabe von eins wird ein neue Textfile mit Testdaten generiert, bei Eingabe von zwei wird ein Pfad zu einem bereit erstellendem Textfile erstellt.

Pfad zu Textfile: Muss wie für das jeweilige OS üblich angegeben werden, in diesem Textfile steht die Kostentabelle  
Start und Endnode wären die Anzahl der Jobs,die angegeben werden oder von der zuvor bereit erstellten Testdaten (Dateinname ist anzugeben).

Format des Textfiles: Erste Zeile bestimmte die Anzahl der Matrix d.h. bei der Angabe 4 werden 4x4 Adjazenmatrix erstellt, ab der zweiten werden die Einträge in einer tabelle geordnet, Einträge sind mit einem Leezeichen voneinander getrennt.
Achtung: die Zählung beginnt von 0, d.h. falls 4 eingegeben wird, ist die letzte Zeile 3. (siehe Beispiel test3)
Es wird nach minimalen Kosten gesucht und am Ende soll jede Person ein Job zugeordnet haben.


Anzahl der Jobs: 5 ist der Standardwert(zwischen 1 und 1000 ist opitmal), wenn ein ungueltiger Wert eingegeben wird, wird eine exeption geworfen.
