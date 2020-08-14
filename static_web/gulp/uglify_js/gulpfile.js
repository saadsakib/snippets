/**
 * Run this task:
 *  npm install gulp-uglify --save-dev
 *  gulp uglify
 * 
 */

var gulp = require('gulp');
var uglify = require('gulp-uglify');

gulp.task('uglify', function() {
  return gulp.src('js/**/*.js')
  .pipe(uglify())
  .pipe(gulp.dest('build'));
});