#!/bin/bash
make
clear
echo "Largeur solver performance :"
echo "Maze size 25x25"
echo
time ./largeur/solver ./mazes/25x25
echo
echo "See above the time for largeur resolution '25x25'"
sleep 6
clear
echo "Now maze size 1000x1000"
echo
time ./largeur/solver ./mazes/1000x1000
echo
echo "See above the time for largeur resolution '1000x1000'"
sleep 6
clear

echo "Empty maze 35x45"
echo
time ./largeur/solver ./mazes/empty_35x45
echo
sleep 6
clear
echo "One wall on maze of 35x45"
echo
time ./largeur/solver ./mazes/one_wall_35x45
echo
sleep 6

clear
echo "Profondeur solver performance :"
echo "Maze size 25x25"
echo
time ./profondeur/solver ./mazes/25x25
echo
echo "See above the time for profondeur resolution '200x200'"
sleep 6
clear
echo "Now maze size 1000x1000"
echo
time ./profondeur/solver ./mazes/1000x1000
echo
echo "See above the time for profondeur resolution '1000x1000'"
sleep 6
clear
make fclean
clear

echo "Empty maze 35x45"
echo
time ./profondeur/solver ./mazes/empty_35x45
echo
sleep 6
clear
echo "One wall on maze of 35x45"
echo
time ./profondeur/solver ./mazes/one_wall_35x45
echo
sleep 6
clear

echo "thanks for watching"
