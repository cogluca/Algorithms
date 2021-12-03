package exercise3;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.assertArrayEquals;

public class UnionFindSetTest {



    private UnionFindSet<Integer> unionFindSetToTest;
    private int element1,element2,element3, element4;

    @Before
    public void initialize() {
        element1 = 5;
        element2 = 30;
        element3 = 3;
        element4 = 4;

        unionFindSetToTest = new UnionFindSet<Integer>();

    }

    @After
    public void afterTest() {}


    /**
     * Testing that recursive search for a root yields same result in different occasions
     */

    @Test
    public void testFindOneRepresentative() throws Exception {

    UnionFindSetNode<Integer> aNode = unionFindSetToTest.makeSet(element1);

    Assert.assertEquals(unionFindSetToTest.findSet(aNode), unionFindSetToTest.findSet(aNode));

    }

    /**
     * Testing that linkage of two roots through rank as a factor yields same result with different ordering of parameters
     */

    @Test
    public void testLinkTwoPoissbleRoots() throws Exception {

        UnionFindSetNode<Integer> aNode = unionFindSetToTest.makeSet(element1);
        UnionFindSetNode<Integer> anotherNode = unionFindSetToTest.makeSet(element2);

        Assert.assertEquals( unionFindSetToTest.linkSet(unionFindSetToTest.findSet(aNode), unionFindSetToTest.findSet(anotherNode)),
                            unionFindSetToTest.linkSet(unionFindSetToTest.findSet(aNode), unionFindSetToTest.findSet(anotherNode)));

    }


    /**
     * Test to find same representative after a union operation
     *
     */

    @Test
    public void sameRepresentative() throws Exception {

        UnionFindSetNode<Integer> aNode = unionFindSetToTest.makeSet(element3);
        UnionFindSetNode<Integer> anotherNode = unionFindSetToTest.makeSet(element4);

        unionFindSetToTest.unionSet(aNode,anotherNode);

        Assert.assertEquals(unionFindSetToTest.findSet(aNode), unionFindSetToTest.findSet(anotherNode));

    }

    /**
     * Testing that the creation of disjoint trees doesn't yield same root
     *
     */


    @Test
    public void differentRepresentative() throws Exception {

        UnionFindSetNode<Integer> nodeOne = unionFindSetToTest.makeSet(element1);
        UnionFindSetNode<Integer> nodeTwo = unionFindSetToTest.makeSet(element2);
        UnionFindSetNode<Integer> nodeThree = unionFindSetToTest.makeSet(element3);
        UnionFindSetNode<Integer> nodeFour = unionFindSetToTest.makeSet(element4);

        unionFindSetToTest.unionSet(nodeOne,nodeTwo);
        unionFindSetToTest.unionSet(nodeThree,nodeFour);

        Assert.assertNotEquals(unionFindSetToTest.findSet(nodeTwo), unionFindSetToTest.findSet(nodeFour));

    }

}
