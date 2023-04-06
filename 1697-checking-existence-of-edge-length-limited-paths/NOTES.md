# **Tricky Question**
​
1) First Look me aaisa lagega ki DFS ya BFS traversal se question solve kr lenge lekin constraints allow nahi karegi Brute Force ke liye.
2) More Optimised way dekho toh Union Find ya Disjoint set se karo toh badhiya tarike se fast solution ho jayega.
3) Ek aur problem ye hai ki isme same nodes ke beech me multiple edges bhi ho sakte hai different value ke.
* Isme pahile sbko edges aur querries ko sort karo dist aur limit ke hisaab se respectively.
* Fir har querry ke liye un edges ko merge karo jinka distance strictly limit se kam ho.
* Ab last me check karo ki querry ke src aur destination node ka parent ek hi hai kya agar haa toh possible hai agar nahi toh possible nahi.
​