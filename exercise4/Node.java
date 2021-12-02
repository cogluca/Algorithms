package exercise4;

import java.util.HashMap;

public class Node<T,L> {

    private T value;
    private HashMap<Node<T,L>, Edge<T,L>> edgeReference;

    public Node(T value) {
        this.value = value;
        this.edgeReference = new HashMap<>();
    }

    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }

    public HashMap<Node<T, L>, Edge<T, L>> getEdgeReference() {
        return edgeReference;
    }

    public void setEdgeReference(HashMap<Node<T, L>, Edge<T, L>> edgeReference) {
        this.edgeReference = edgeReference;
    }






}
