#' Call TinySegmenter
#'
#' @param text character vector
#' @param ... all other args are passed to \code{jsonlite::fromJSON}
#' @return list
#'
#' @import purrr
#' @importFrom stringi stri_enc_toutf8
#' @importFrom jsonlite fromJSON
#' @export
segment <- function(text, ...) {
  json <- segmenter(stringi::stri_enc_toutf8(text))
  res <- lapply(json, function(elem) {
    Encoding(elem) <- "UTF-8"
    return(jsonlite::fromJSON(elem, ...))
  })
  return(purrr::map(res, ~ purrr::discard(., ~ . == "")))
}
