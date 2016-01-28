/* Schreibe in diese Datei das Briefing
 *
 * Das Briefing wird vom W_FRAMEWORK mit eingebunden
 * Einträge sind nach folgendem Schema eingebunden:
 *
 * player createDiaryRecord ["Diary",["ÜBERSCHRIFT","INHALT"]];
 *
 * Formatierungsbefehle sind:
 *  <br/>                                               - Zeilenumbruch
 *  <t/>                                                - Tabulator
 *  <marker name='MARKER'>TEXT</marker>                 - Verlinkt den TEXT auf den MARKER
 *  <img image='BILDPFAD' width='200' height='200'/>    - Bindet das Bild mit angegebener Breite und Höhe unter BILDPFAD ein
 *
 * Ein Beispiel ist unten mit angegeben.
 *
 */

player createDiaryRecord ["Diary",["Technisches","
Diese Mission wurde mit Gruppe Ws Missionstemplate von [W] Fett_Li erstellt.<br/>
Inhalt dieses Templates ist:<br/>
<t/>W_VD - Viewdistancescript<br/>
<t/>W_Teleporter - Teleport-Menü<br/>
<t/>W_Loadouts - Loadoutskripte<br/>
<br/>
"]];
