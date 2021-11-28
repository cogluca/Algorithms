package exercise3;

import java.util.HashMap;

public class UnionFindSet<T> {

    HashMap<T, UnionFindSetNode<T>> map;


    public UnionFindSet() {
        map = new HashMap<>();
    }


    public UnionFindSetNode<T> makeSet(T x) {
        if (x != null) {
            map.put(x, new UnionFindSetNode<>(x));
            return map.get(x);
        }
        return null;
    }


    public UnionFindSetNode<T> unionSet(UnionFindSetNode<T> x, UnionFindSetNode<T> y) {
       return linkSet(findSet(x), findSet(y));
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

    public UnionFindSetNode<T> findSet(UnionFindSetNode<T> x) {
        UnionFindSetNode<T> treeClimbingNode = x;
        if(x == null)
            return null;
        if (!x.equals(x.getParent())) {
            treeClimbingNode = findSet(treeClimbingNode.getParent());
        }
        return treeClimbingNode;
    }

}
