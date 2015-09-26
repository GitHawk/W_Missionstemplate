
/* 		Die init.sqf
 *
 * Die init.sqf ist eine Datei, die bei Missionsstart autoatmisch sowohl auf dem Server,
 * als auch bei allen Spielern ausgeführt wird.
 * sie eignet sich daher am besten für im Netzwerk globale Variablen.
 *
 * In ArmA II war sie noch hochfrequentiert, durch die hoch differenzierten init-Dateien
 * in ArmA III findet sie kaum noch Verwendung.
 *
 * Weitere Informationen findet ihr hier:
 *		https://community.bistudio.com/wiki/Initialization_Order
 *		https://community.bistudio.com/wiki/Event_Scripts
 */

// TFAR Einstellungen:
// Diese Variable deaktiviert das Verteilen der Microdagr durch TFAR
TF_give_microdagr_to_soldier = false;

// Viewdistance Einstellungen - vor gewünschten Variablen einfach das Kommentarzeichen entfernen.
// Diese Variable legt die einstellbare Maximalsichtweite für Terrain fest.
FETT_VD_MAX = 12000;
// Diese Variable legt die einstellbare Maximalsichtweite für Objekte fest.
FETT_VD_MAX_OBJ = 3500;
// Diese Variable deaktiviert, ob Spieler das Gras austellen können
// FETT_VD_DISABLE_NOGRASS = true;
// Diese Variable aktiviert, dass alle Spieler die Terraineinstellungen auf der höchsten Stufe haben
// FETT_VD_FORCE_HIGHTERRAIN = true;
