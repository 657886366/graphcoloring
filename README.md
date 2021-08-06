# graphcoloring

inFile1 (use argv[1]): a text file contains a list of bi-directional edges,
representing an undirected graph, G=<N, E>.   A bi-directional edge in the data file should be treated as having two edges.  For example, an undirected edge <3, 5> in the data file,  means one directed edge from 3 to 5 and another directed edge from 5 to 3.

The input file format is as follows:
The first number in inFile1 is the number of nodes in the graph; 
	then follows by a list of undirected edges  <ni, nj>.  
	

For example 
8     	// 8 nodes in the graph
1 2 	 
4 1
2 4



Method 1 (or 2)  was used to color the graph.  // The first output text-line
 Below is the result of the color assignments.  // The second output text-line
						// Provide a blank text-line       
8     	// 8 nodes in the graph
	1  1	// node 1 colored with 1st color
	2  3	// node 2  colored with 3rd color
