#include "Map.h"
// general code(cell id) for a cell is like "h_01_23" i.e <region(h-hall,s-solar,d-dungeon)_<x_coordinate in doubledigits>_<y_coordinate in double digs>
// identifier for cell shallbe h0123
//Starts towards East

//Hallway-1
Cell h_01_03("h_01_03", "Hallway-1 Entrance");
Cell h_02_03("h_02_03", "Hallway-1");
Cell h_03_03("h_03_03", "Hallway-1");
Cell h_04_03("h_04_03", "Hallway-1");
Cell h_05_03("h_05_03", "Hallway-1 to Hallway-2 turn");//East+South Turn

//Hallway-2
//h(5,4)-h(5,10)

Cell h_05_04("h_05_04", "Hallway-2");
Cell h_05_05("h_05_05", "Hallway-2");
Cell h_05_05("h_05_06", "Hallway-2");
Cell h_05_07("h_05_07", "Hallway-2");
Cell h_05_08("h_05_08", "Hallway-2");
Cell h_05_09("h_05_09", "Hallway-2");
Cell h_05_10("h_05_10", "Hallway-2 to Hallway-3 turn");//North+East Turn

//Hallway-3
//h(6,10) - h(22,10)
Cell h_06_10("h_06_10", "Hallway-3");
Cell h_07_10("h_07_10", "Hallway-3");
Cell h_08_10("h_08_10", "Hallway-3 with a South passage(Hallway-5)");//South+(East/West) turn , south passsage = Hallway-5
Cell h_09_10("h_09_10", "Hallway-3");
Cell h_10_10("h_10_10", "Hallway-3");
Cell h_11_10("h_11_10", "Hallway-3");
Cell h_12_10("h_12_10", "Hallway-3");
Cell h_13_10("h_13_10", "Hallway-3");
Cell h_14_10("h_14_10", "Hallway-3");
Cell h_15_10("h_15_10", "Hallway-3");
Cell h_16_10("h_16_10", "Hallway-3");
Cell h_17_10("h_17_10", "Hallway-3");
Cell h_18_10("h_18_10", "Hallway-3");
Cell h_19_10("h_19_10", "Hallway-3");
Cell h_20_10("h_20_10", "Hallway-3");
Cell h_21_10("h_21_10", "Hallway-3");
Cell h_22_10("h_22_10", "Hallway-3 to Hallway-4 turn");//(North/South) + West turn


//Hallway-5
//h(8,11)-h(8,22)

Cell h_08_11("h_08_11", "Hallway-5");
Cell h_08_12("h_08_12", "Hallway-5");
Cell h_08_13("h_08_13", "Hallway-5");
Cell h_08_14("h_08_14", "Hallway-5");
Cell h_08_15("h_08_15", "Hallway-5");
Cell h_08_16("h_08_16", "Hallway-5");
Cell h_08_17("h_08_17", "Hallway-5");
Cell h_08_18("h_08_18", "Hallway-5 with a East passage(Hallway-6)");//East + (North/South) turn 
Cell h_08_19("h_08_19", "Hallway-5");
Cell h_08_20("h_08_20", "Hallway-5");
Cell h_08_21("h_08_21", "Hallway-5");
Cell h_08_22("h_08_22", "Hallway-5 to Hallway-7 turn"); //West + North

//Hallway-7 
//h(8,22)- h(4,22)
