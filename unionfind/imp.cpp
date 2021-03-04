//1. Make a edge b/w 2 nodes iff they are NOT in the same CC
// a  ----  b
if (find_set(a) != find_set(b))
			union_sets(a, b);
else {
		  // edge b/w a and b is redundant, dont construct it
}

//2. Count CC after the union_set funcs OR connect all isolated CCs
// Check if a node is connected to an arbitrary node, say 1
// if not connected to 1, ++CC
int cc = 1;
for (int i = 2; i <= n; ++i) {
		if (find_set(1) != find_set(i)) {
			// you can add an edge b/w 1 and i to join them      
			union_sets(1, i);// adding that edge
      
      cc++;
		}
}

