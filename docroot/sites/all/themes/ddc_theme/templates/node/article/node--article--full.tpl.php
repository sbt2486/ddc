<?php
/**
 * @file
 * Template file for article full view.
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <article>
    <div class="media">
      <div class="pull-right">
        <?php print render($content['field_image']); ?>
      </div>
      <div class="media-body">
        <h1><?php print $title; ?></h1>
        <h3><?php print $field_subtitle[0]['safe_value']; ?></h3>
        <?php print render($content['field_publication_date']); ?>
        <?php print render($content['body']); ?>
        <br />
        <?php if ($uid): ?>
          <?php print $author; ?>
        <?php endif; ?>
      </div>
    </div>
  </article>
</div>
