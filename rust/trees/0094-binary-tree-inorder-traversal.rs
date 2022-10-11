// Threaded Binary Tree / Morris Traversal
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn inorder_traversal(mut root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut visited = vec![];
        while root.is_some() {
            let root_rc = root.clone().unwrap();
            let root_ref = root_rc.borrow();

            if root_ref.left.is_some() {
                let mut pre = root_ref.left.clone();
                loop {
                    let pre_rc = pre.clone().unwrap();
                    let p_ref = pre_rc.borrow();
                    if p_ref.right.is_none() || p_ref.right == root {break};

                    pre = p_ref.right.clone();
                }

                let mut pre = pre.unwrap();
                let mut pre = pre.borrow_mut();
                if pre.right.is_none() {
                    pre.right = root.clone();
                    root = root_ref.left.clone();
                } else {
                    pre.right = None;
                    visited.push(root_ref.val);
                    root = root_ref.right.clone();
                }
            } else {
                visited.push(root_ref.val);
                root = root_ref.right.clone();
            }
        }

        visited
    }
}