package exercise3;

import java.util.HashMap;

public class UnionFindSet<T> {

    HashMap<T, UnionFindSetNode<T>> map;


    public UnionFindSet() {
        map = new HashMap<>();
    }


    public void makeSet(T x) {
        if (x != null) {
            map.put(x, new UnionFindSetNode<>(x));
        }
    }


    public void unionSet(UnionFindSetNode<T> x, UnionFindSetNode<T> y) {
        linkSet(findSet(x), findSet(y));
    }


    public void linkSet(UnionFindSetNode<T> x, UnionFindSetNode<T> y) {
        if (x.getRank() > y.getRank()) {
            y.setParent(x);
        } else
            x.setParent(y);
        if (x.getRank() == y.getRank()) {
            y.setRank(y.getRank() + 1);
        }

    }

    public UnionFindSetNode<T> findSet(UnionFindSetNode<T> x) {
        UnionFindSetNode<T> treeClimbingNode = x;
        if (!x.equals(x.getParent())) {
            treeClimbingNode = findSet(treeClimbingNode);
        }
        return treeClimbingNode;
    }

}
