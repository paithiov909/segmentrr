// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#ifndef RCPP_segmentrr_RCPPEXPORTS_H_GEN_
#define RCPP_segmentrr_RCPPEXPORTS_H_GEN_

#include <Rcpp.h>

namespace segmentrr {

    using namespace Rcpp;

    namespace {
        void validateSignature(const char* sig) {
            Rcpp::Function require = Rcpp::Environment::base_env()["require"];
            require("segmentrr", Rcpp::Named("quietly") = true);
            typedef int(*Ptr_validate)(const char*);
            static Ptr_validate p_validate = (Ptr_validate)
                R_GetCCallable("segmentrr", "_segmentrr_RcppExport_validate");
            if (!p_validate(sig)) {
                throw Rcpp::function_not_exported(
                    "C++ function with signature '" + std::string(sig) + "' not found in segmentrr");
            }
        }
    }

    inline Rcpp::CharacterVector segmenter(Rcpp::CharacterVector v) {
        typedef SEXP(*Ptr_segmenter)(SEXP);
        static Ptr_segmenter p_segmenter = NULL;
        if (p_segmenter == NULL) {
            validateSignature("Rcpp::CharacterVector(*segmenter)(Rcpp::CharacterVector)");
            p_segmenter = (Ptr_segmenter)R_GetCCallable("segmentrr", "_segmentrr_segmenter");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_segmenter(Shield<SEXP>(Rcpp::wrap(v)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::CharacterVector >(rcpp_result_gen);
    }

}

#endif // RCPP_segmentrr_RCPPEXPORTS_H_GEN_
