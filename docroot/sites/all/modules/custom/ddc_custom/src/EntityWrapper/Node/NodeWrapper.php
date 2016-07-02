<?php

/**
 * @file
 * Provides an extended entity wrapper class for node entities.
 */

namespace Drupal\ddc_custom\EntityWrapper\Node;

use \EntityDrupalWrapper;

class NodeWrapper extends EntityDrupalWrapper {

  /**
   * Wrap a node object.
   *
   * @param int|object $data
   *   A node id or a node object.
   */
  public function __construct($data) {
    parent::__construct('node', $data);
  }

  /**
   * Checks whether a node is accessible for anonymous users.
   *
   * Nodes that are highlighted but not fully published yet (full publication
   * date field), are restricted.
   *
   * @return bool
   *   TRUE if the node is highlighted but full publication date has passed,
   *   FALSE otherwise.
   *
   * @throws \Exception
   */
  public function articleIsPublic() {
    if ($this->getBundle() != 'article') {
      throw new \Exception('Only nodes of bundle article can be checked');
    }

    $publication_timestamp = 0;
    if ($this->field_full_publication_date->value()) {
      $publication_timestamp = $this->field_full_publication_date->value();
    }
    return !($this->articleIsHighlighted() && time() < $publication_timestamp);
  }

  /**
   * Checks whether the given node is flagged as highlighted.
   *
   * @return bool
   *   TRUE if the node is highlighted, FALSE otherwise.
   *
   * @throws \Exception
   */
  function articleIsHighlighted() {
    if ($this->getBundle() != 'article') {
      throw new \Exception('Only nodes of bundle article can be highlighted');
    }

    return $this->field_highlighted->value();
  }

  /**
   * Renders the author of the node.
   *
   * @return string
   *   The resulting markup after rendering the node author's user profile.
   */
  function renderNodeAuthor() {
    $account = $this->author->value();

    // Retrieve all profile fields and attach to $account->content.
    user_build_content($account);
    $user_profile = $account->content;
    // We don't need duplicate rendering info in account->content.
    unset($account->content);
    $user_profile += array(
      '#theme' => 'user_profile',
      '#account' => $account,
    );
    return drupal_render($user_profile);
  }

}
