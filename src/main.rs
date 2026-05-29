#[derive(Debug)]
struct TreeNode {
    val: i32,
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}

impl TreeNode {
    fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

fn insert(node: &mut Option<Box<TreeNode>>, val: i32) {
    match node {
        Some(current) => {
            if val < current.val {
                insert(&mut current.left, val);
            } else {
                insert(&mut current.right, val);
            }
        }
        None => {
            *node = Some(Box::new(TreeNode::new(val)));
        }
    }
}

// fn traverse(node: &Option<Box<TreeNode>>) {
//     if let Some(n) = node {
//         println!("{}", n.val);
//         traverse(&n.left);
//         traverse(&n.right);
//     }
// }

// fn main() {
//     let mut root = Some(Box::new(TreeNode::new(10)));

//     if let Some(ref mut node) = root {
//         node.left = Some(Box::new(TreeNode::new(5)));
//         node.right = Some(Box::new(TreeNode::new(15)));
//     }

//     insert(&mut root, 10);
//     insert(&mut root, 20);
//     insert(&mut root, 13);

//     println!("{:#?}", root);
//     traverse(&root);
// }

// Level Order traversal
use std::collections::VecDeque;

fn bfs(root: &Option<Box<TreeNode>>) {
    let mut queue = VecDeque::new();

    if let Some(node) = root {
        queue.push_back(node);
    }

    while let Some(current) = queue.pop_front() {
        println!("{}", current.val);

        if let Some(ref left) = current.left {
            queue.push_back(left);
        }

        if let Some(ref right) = current.right {
            queue.push_back(right);
        }
    }
}

fn max_depth(node: &Option<Box<TreeNode>>) -> i32 {
    match node {
        Some(n) => {
            let left_depth = max_depth(&n.left);
            let right_depth = max_depth(&n.right);
            left_depth.max(right_depth) + 1
        }
        None => 0,
    }
}

fn count_leaf_nodes(node: &Option<Box<TreeNode>>) -> i32 {
    match node {
        Some(n) => {
            if n.left.is_none() && n.right.is_none() {
                1
            } else {
                count_leaf_nodes(&n.left) + count_leaf_nodes(&n.right)
            }
        }
        None => 0,
    }
}

fn main() {
    let mut root: Option<Box<TreeNode>> = None;

    insert(&mut root, 10);
    insert(&mut root, 5);
    insert(&mut root, 15);
    insert(&mut root, 2);
    insert(&mut root, 7);

    println!("BFS:");
    bfs(&root);
    println!("max dept {}", max_depth(&root));
}
