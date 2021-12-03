package exercise4;

import exercise3.UnionFindSet;
import exercise4.Datastructure.Compare;
import exercise4.Datastructure.Edge;
import exercise4.Datastructure.Graph;
import exercise4.Datastructure.Node;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;


public class Kruskal {


    public void tryKruskal() throws Exception {

        Graph<String, Float> graph = new Graph<>(false);
        UnionFindSet<Node<String, Float>> unionFindSet = new UnionFindSet<>();
        ArrayList<Edge<String, Float>> listOfEdges = new ArrayList<>();

        listOfEdges.addAll(graph.getEdges());

        for (Node<String, Float> iteratedNode : graph.getNodes()) {
            unionFindSet.makeSet(iteratedNode);
        }

        Collections.sort(listOfEdges, new Compare());

        for (Edge<String, Float> edge : listOfEdges) {
            // System.out.println(" " + arc.getNodeFrom().getValue() + " - " +
            // arc.getNodeTo().getValue());
            if (unionFindSet.findSet(edge.getFirstNode()) != unionFindSet.findSet(edge.getSecondNode())) {
                if (!graph.containsNode(edge.getFirstNode().getValue())) {
                    graph.addNode(edge.getFirstNode().getValue());
                }
                if (!graph.containsNode(edge.getSecondNode().getValue())) {
                    graph.addNode(edge.getSecondNode().getValue());
                }
                unionFindSet.unionSet(edge.getFirstNode(), edge.getSecondNode());
                if (!graph.containsEdge(edge.getFirstNode().getValue(), edge.getSecondNode().getValue())) {
                    graph.addEdge(edge.getFirstNode().getValue(), edge.getFirstNode().getValue(), edge.getLabel());
                }
            }


        }


    }
}
