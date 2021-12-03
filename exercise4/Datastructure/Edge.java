package exercise4.Datastructure;

public class Edge<T,L> {

    private L label;
    private Node<T,L> firstNode;
    private Node<T,L> secondNode;

    /**
     * Constructor for an edge in a Node
     * @param label generic label that can contain a weight or any other value that an arc can hold
     * @param firstNode in an undirected graph indicates one of the two nodes forming the edge, in a directed one it's the starting node
     * @param secondNode in an undirected graph indicates one of the two nodes forming the edge, in a directed one it's the destination node
     */

    public Edge(L label, Node<T,L> firstNode, Node<T,L> secondNode) {
        this.label = label;
        this.firstNode = firstNode;
        this.secondNode = secondNode;
    }

    public L getLabel() {
        return label;
    }

    public void setLabel(L label) {
        this.label = label;
    }

    public Node<T, L> getFirstNode() {
        return firstNode;
    }

    public void setFirstNode(Node<T, L> firstNode) {
        this.firstNode = firstNode;
    }

    public Node<T, L> getSecondNode() {
        return secondNode;
    }

    public void setSecondNode(Node<T, L> secondNode) {
        this.secondNode = secondNode;
    }



}
