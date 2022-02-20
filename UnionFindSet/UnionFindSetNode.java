package UnionFindSet;

public class UnionFindSetNode<T> {

    private T element;
    private int rank;
    private UnionFindSetNode parent;

    public UnionFindSetNode(T elementToInsert) {
        this.element = elementToInsert;
        this.rank = 0;
        this.parent = this;
    }

    public T getElement() {
        return element;
    }

    public void setElement(T element) {
        this.element = element;
    }

    public int getRank() {
        return rank;
    }

    public void setRank(int rank) {
        this.rank = rank;
    }

    public UnionFindSetNode getParent() {
        return parent;
    }

    public void setParent(UnionFindSetNode parent) {
        this.parent = parent;
    }


}
