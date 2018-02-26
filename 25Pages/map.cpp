// "map<key_type, value_type> m;
// "map<key_type, value_type, cmp> m;
map<int, int, greater<int> > dec_intmap; //less<int> by default
//use m.count(x) to search if its present or not. 