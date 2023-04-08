# Tricky Question
Pehle lagega ki src1 se dist lelu aur src2 se lelu fir dono ko add krdu this is wrong.
fir lagega ki (src1 se aur src 2 se dest) ka dist aur (src1 se src2 and src2 se dest) ka dist aur (src2 se src1 and src1 se dest) ka dist mese minimum distance hi answer hoga lekin ye bhi galat hoga kisi node se overall distance kam ho sakta hai teeno ka.
​
### Actual Solution
Stepwise:
1. Src1 se saare nodes ka minimum distance nikalo.
2. Src 2 se saare nodes ka minimum distance nikalo.
3. Dest se saare nodes ka minimum distance nikalo.
4. Loop chalao dekho kist node se teeno ka distance minimum hai wahi answer hai.
​
​
​