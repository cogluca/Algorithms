package exercise4.datastructure;

public class Edge<T,L> {

    private L label;
    private Node<T,L> firstNode;
    private Node<T,L> secondNode;

    public Edge(L label, Node<T,L> firstNode, Node<T,L> secondNode) {
        this.label = label;
        this.firstNode = firstNode;
        this.secondNode = secondNode;
    }

    public L getLabel() {
        return label;
    }

    public Node<T, L> getFirstNode() {
        return firstNode;
    }

    public Node<T, L> getSecondNode() {
        return secondNode;
    }



}
