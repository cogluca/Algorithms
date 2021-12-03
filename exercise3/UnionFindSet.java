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


    public UnionFindSetNode<T> unionSet(T x, T y) {

        UnionFindSetNode<T> firstNode = map.get(x);
        UnionFindSetNode<T> secondNode = map.get(y);


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
        UnionFindSetNode<T> r = map.get(element);

        if (r == null)
            return null;

        return findSet(r).getElement();
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
