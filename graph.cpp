#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>

/*
  Name: Avanish Joshi
  Date: 6/6/2023
  Project: This is a graph creator. It allows the user to add and remove vertices and edges.
  The edges are given a chosen weight and the vertices are given unique labels. The shortest
  path can be found. 
 */

using namespace std;

void dijkstraAlg(string vertex, int table[20][20], map<string, int> &count, map<string, vector<string>> connections, vector<string> &visted, vector<string> &unvisted, map<string, int> vertexList, map<string, int> &paths);

int main()
{
  // setting up the main table and variables
    int table[20][20];
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            table[i][j] = 0;
        }
    }
    map<string, int> vertexList;
    map<string, vector<string>> connections;
    vector<string> tokens;
    
    while(true) {
      cout << " " << endl;
        cout << "1 to add edge, 2 to add vertex, 3 to delete edge, 4 to delete vertex, 5 for shortest path, 6 to print, 7 to quit" << endl;
        int input;
        cin >> input;
        if(input == 1) {
	  // adding an edge
	  cout << " " << endl;
            cout << "Type the first vertex" << endl;
            string first;
            string second;
            cin >> first;
	    cout << "Type the second vertex" << endl;
            cin >> second;
            if(vertexList[first] != 0 && vertexList[second] != 0) {
                int weight;
                cout << "Type a weight" << endl;
                cin >> weight;
		// presents the connection in the table
                table[vertexList[first]][vertexList[second]] =  weight; 
                table[vertexList[second]][vertexList[first]] =  weight;
		// adds to connections vector
                connections[first].push_back(second);
                connections[second].push_back(first);
            }
            else {
	      vertexList.erase(first);
              cout  << "You need 2 existing vertices" << endl;
            }
            cin.get();
        }
        else if(input == 2) {
	  // adding a vertex
	  cout << " " << endl;
	  cout << "Type vertex label to create" << endl;
	  string first;
                cin >> first;
                if(vertexList[first] == 0) {
		  // adds to tokens and vertex list
		  tokens.push_back(first);
                    vertexList[first] = vertexList.size();
                }
                else
		  {
                    cout << "Label name already taken" << endl;
		  }
            cin.get();
        }
        else if(input == 3) {
	  // deleting an edge
	  cout << " " << endl;
            string first;
            string second;
            cout << "Type first vertex" << endl;
            cin >> first;
	    cout << "Type second vertex" << endl;
            cin >> second;
	    if (vertexList[first] != 0 && vertexList[second] != 0)
	      {
		if(vertexList[second] > 0 && vertexList[first] > 0) {
		  // sets display values on table to 0
		  table[vertexList[second]][vertexList[first]] = 0;
		  table[vertexList[first]][vertexList[second]] = 0;
		}
	      }
	    else
	      {
		vertexList.erase(first);
		cout << "Vertex labels do not exist" << endl;
	      }
            cin.get();
        }
        else if(input == 4) {
	  // deleting a vertex
	  cout << " " << endl;
            string first;
	    cout << "Type vertex label to delete" << endl;
            cin >> first;
            

	    if (vertexList[first] != 0)
	      {
		// deletes any connecting edges
		for (int i = 0; i < tokens.size(); i++)
		  {
		
		    if(vertexList[tokens[i]] > 0 && vertexList[first] > 0) {
		      table[vertexList[tokens[i]]][vertexList[first]] = 0;
		      table[vertexList[first]][vertexList[tokens[i]]] = 0;
		    }
		
		  }

		// deletes the vertex
		for (int i = 0; i < tokens.size(); i++)
		  {
		    if (tokens[i] == first)
		      {
			vertexList.erase(first);
		      }
		  }
	      }
	    else
	      {
		vertexList.erase(first);
		cout << "Vertex does not exist" << endl;
	      }

	    
            cin.get();
        }
        else if(input == 5)
	  {
	    // finding shortest path
	  cout << " " << endl;
            cout << "Vertex to find shortest paths for:" << endl;
            string vertex;
            cin >> vertex;

	    // setting paths to a high amount
            map<string, int> count;
            map<string, int> paths;
            for(int i = 0; i < tokens.size(); i++) {
                paths[tokens[i]] = 100000;
            }

	    // Inspiration and help from: Sahil P.
	    
	    // creating visited and unvistied vertices vectors and assigining an unmodifiable
	    // constant reference to the strings in the vector
            vector<string> visited;
            vector<string> unvisited;
            for (auto const &p: vertexList) {
                unvisited.push_back(p.first);
            }

	    // calling the algorithm
            dijkstraAlg(vertex, table, count, connections, visited, unvisited, vertexList, paths);

	    // printing the names and their paths
	    for (auto const &p: paths) {
                cout << (p.first) << ":" << (p.second) << endl;
            }
            
            
            cin.get();
        }
        else if(input == 6)
	  {
	    //printing the table
	    
	    cout << " " << endl;
	  for(int i = 0; i < vertexList.size() + 1; i++) {
	    for(int j = 0; j < vertexList.size() + 1; j++) {

	      //printing names
	      if (i == 0 && j != 0)
		{
		  cout << tokens[j - 1] << "\t";
		}
	      else if (j == 0 && i != 0)
		{
		  cout << tokens[i - 1] << "\t";
		}
	      else
		{
		  // printing values
		  cout << table[i][j] << "\t";
		}
              }
                cout << endl;
            }
	  cout << " " << endl;
            cout << "Vertices: " << vertexList.size() << endl;
            cin.get();
        }
	else if (input == 7)
	  {
	    cout << "Quit" << endl;
	    return 0;
	  }
         
    }
    
    return 0;
}

void dijkstraAlg(string vertex, int table[20][20], map<string, int> &count, map<string, vector<string>> connections, vector<string> &visited, vector<string> &unvisited, map<string, int> vertexList, map<string, int> &paths) {

  // iterating through all the connections to the vertex and counting the connection weight values from the table
  for(int i = 0; i < connections[vertex].size(); i++) {
    count[connections[vertex][i]] += table[vertexList[vertex]][vertexList[connections[vertex][i]]];
    //cout << count[connections[vertex][i]] << endl;
    if(count[connections[vertex][i]] < paths[connections[vertex][i]]) {
       paths[connections[vertex][i]] =  count[connections[vertex][i]];
     }
    }
        
   for(int i = 0; i < unvisited.size(); i++) {
     if(unvisited[i] == vertex) {
       unvisited[i] = -1;
     }
   }

   // stop if visited all
   visited.push_back(vertex);
   if(visited.size() ==  vertexList.size()) {
     return;
   }

   // iterating through the unvisited vertices
   for(int i = 0; i < unvisited.size(); i++) {
     string s = unvisited[i];
     for(int j = 0; j < connections[vertex].size(); j++) {
       if(connections[vertex][j] == unvisited[i]) {
	 dijkstraAlg(connections[vertex][j], table, count, connections, visited, unvisited, vertexList, paths);
       }
     }
   }
}
