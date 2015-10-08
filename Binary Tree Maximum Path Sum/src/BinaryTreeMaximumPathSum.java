
public class BinaryTreeMaximumPathSum {
	public int max;
    public int lrm(TreeNode root){
       if(root==null)
           return 0;
       int l = lrm(root.left);
       int r = lrm(root.right);
       int m = (l>r)?l:r;
       m=(m<0)?root.val:m+root.val;
       max=(l+root.val+r>max)?l+root.val+r:max; 
       max=(m>max)?m:max;
       return m;
   }
   public int maxPathSum(TreeNode root) {
      max= Integer.MIN_VALUE;
      lrm(root);
      return max;
   }
}
