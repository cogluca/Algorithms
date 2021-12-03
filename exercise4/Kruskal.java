package exercise4;

import exercise4.Datastructure.Edge;
import exercise4.Datastructure.Graph;

import java.util.ArrayList;
import java.util.Collection;


public class Kruskal {

    Graph graph;


    public Kruskal(boolean directed) {
        this.graph = new Graph(directed);
    }

    Collection<Edge<String,Float>> toSortEdges = graph.getEdges();
    ArrayList<Edge<String,Float>> sortedEdges = new ArrayList<>();







}
