/**
 * @file r_tree_split.hpp
 * @author Andrew Wells
 *
 * Defintion of the RTreeSplit class, a class that splits the nodes of an R
 * tree, starting at a leaf node and moving upwards if necessary.
 */
#ifndef MLPACK_CORE_TREE_RECTANGLE_TREE_R_TREE_SPLIT_HPP
#define MLPACK_CORE_TREE_RECTANGLE_TREE_R_TREE_SPLIT_HPP

#include <mlpack/core.hpp>

namespace mlpack {
namespace tree /** Trees and tree-building procedures. */ {

/**
 * A Rectangle Tree has new points inserted at the bottom.  When these
 * nodes overflow, we split them, moving up the tree and splitting nodes
 * as necessary.
 */
template<typename TreeType>
class RTreeSplit
{
 public:
  //! Default constructor
  RTreeSplit();

  //! Construct this with the specified node.
  RTreeSplit(TreeType *node);

  //! Construct this with the specified node and the parent of the node.
  RTreeSplit(TreeType *node,const TreeType *parentNode);

  //! Create a copy of the other.split.
  RTreeSplit(TreeType *node,const TreeType &other);

  /**
   * Split a leaf node using the "default" algorithm.  If necessary, this split
   * will propagate upwards through the tree.
   */
  void SplitLeafNode(std::vector<bool>& relevels);

  /**
   * Split a non-leaf node using the "default" algorithm.  If this is a root
   * node, the tree increases in depth.
   */
  bool SplitNonLeafNode(std::vector<bool>& relevels);

 private:
  //! The node which has to be split.
  TreeType *tree;

  /**
   * Get the seeds for splitting a leaf node.
   */
  void GetPointSeeds(int& i, int& j);

  /**
   * Get the seeds for splitting a non-leaf node.
   */
  void GetBoundSeeds(int& i, int& j);

  /**
   * Assign points to the two new nodes.
   */
  static void AssignPointDestNode(TreeType* oldTree,
                                  TreeType* treeOne,
                                  TreeType* treeTwo,
                                  const int intI,
                                  const int intJ);

  /**
   * Assign nodes to the two new nodes.
   */
  static void AssignNodeDestNode(TreeType* oldTree,
                                 TreeType* treeOne,
                                 TreeType* treeTwo,
                                 const int intI,
                                 const int intJ);

  /**
   * Insert a node into another node.
   */
  static void InsertNodeIntoTree(TreeType* destTree, TreeType* srcNode);
};

} // namespace tree
} // namespace mlpack

// Include implementation
#include "r_tree_split_impl.hpp"

#endif
