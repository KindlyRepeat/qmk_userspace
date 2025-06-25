```
 mv ~/Downloads/bastardkb_dilemma_3x5_2_assembled_layout_split_3x5_2_mine.json
 ./bastardkb_dilemma_3x5_2_assembled_layout_split_3x5_2_mine.json
 
 qmk json2c -o layout.c ./bastardkb_dilemma_3x5_2_assembled_layout_split_3x5_2_mine.json
 
 qmk compile -kb bastardkb/dilemma/3x5_2/assembled -km kindlyrepeat
 qmk flash -kb bastardkb/dilemma/3x5_2/assembled -km kindlyrepeat
```
