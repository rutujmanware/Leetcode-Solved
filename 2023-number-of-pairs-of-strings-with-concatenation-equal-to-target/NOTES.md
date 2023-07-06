**Good Approach**
I find this approach very impressive in terms of time complexity.
just count the frequency of every string store in in a map then, run a loop on map and check if any string is equal to the substring of target string of same size as that of the current string.
Store remaining part of target string in another string variable say "s" and then fetch the frequency of s from the map.
then it is simple math and keep it mind if prefix and suffix are equal case.