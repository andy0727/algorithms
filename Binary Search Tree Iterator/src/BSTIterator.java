import java.util.Stack;


public class BSTIterator {
	Stack<TreeNode> s=new Stack<TreeNode>();
	private void updateStack(TreeNode iter){
		while(iter!=null){
			s.push(iter);
			iter=iter.left;
		}
	}
	public BSTIterator(TreeNode root) {
        this.updateStack(root);
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return (!s.empty());
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode tmp= s.pop();
        if(tmp!=null){
        	this.updateStack(tmp.right);
        	return tmp.val;
        }
        return -1;
    }
}
