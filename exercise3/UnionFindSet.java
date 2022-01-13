package exercise3;

import java.util.HashMap;

public class UnionFindSet<T> {

    HashMap<T, UnionFindSetNode<T>> map;


    public UnionFindSet() {
        map = new HashMap<>();
    }


    public UnionFindSetNode<T> makeSet(T x) throws Exception {
        if (x != null) {
            map.put(x, new UnionFindSetNode<>(x));
            return map.get(x);
        }
        throw new Exception("Didn't make the set correctly");
    }


    public UnionFindSetNode<T> unionSet(T x, T y) throws Exception {

        UnionFindSetNode<T> firstNode = map.get(x);
        UnionFindSetNode<T> secondNode = map.get(y);

        if(firstNode == null || secondNode == null)
            throw new Exception("Reference nodes are non existent");

        return linkSet(findSet(firstNode), findSet(secondNode));
    }


    public UnionFindSetNode<T> linkSet(UnionFindSetNode<T> x, UnionFindSetNode<T> y) {
        if(x == null || y == null)
            return  null;
        if (x.getRank() > y.getRank()) {
            y.setParent(x);
            return x;
        } else {
            x.setParent(y);
            if (x.getRank() == y.getRank()) {
                y.setRank(y.getRank() + 1);
            }
            return y;
        }
    }

    public T findSet(T element){
        UnionFindSetNode<T> aNode = map.get(element);

        if (aNode == null)
            return null;

        return findSet(aNode).getElement();
    }

    public UnionFindSetNode<T> findSet(UnionFindSetNode<T> x) {
        UnionFindSetNode<T> treeClimbingNode = x;
        if(x == null)
            return null;
        if (!x.equals(x.getParent())) {
            treeClimbingNode.setParent(findSet(treeClimbingNode.getParent()));
        }
        return treeClimbingNode.getParent();
    }

}
