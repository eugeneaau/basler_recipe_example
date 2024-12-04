// Include files to use the pylon API.
#include <pylon/PylonIncludes.h>
// Extend the pylon API for using pylon data processing.
#include <pylondataprocessing/PylonDataProcessingIncludes.h>
// The sample uses the std::vector.
#include <vector>

// Declare a data class for one set of output data values.
class ResultData
{
public:
    ResultData()
        : hasError(false)
    {
    }

    std::vector<Pylon::DataProcessing::SPointF2D> positions_px;
    std::vector<double> scores;
    Pylon::StringList_t texts;
    Pylon::StringList_t texts2;

    bool hasError;                  // If something doesn't work as expected
                                    // while processing data, this is set to true.
    Pylon::String_t errorMessage;   // Contains an error message if
                                    // hasError has been set to true.

    void fromVariantContainer(const Pylon::DataProcessing::CVariantContainer& variantContainer)
    {
        // Positions_px
        auto posPositions_px = variantContainer.find("Positions_px");
        if (posPositions_px != variantContainer.end())
        {
            const Pylon::DataProcessing::CVariant& value = posPositions_px->second;
            if (value.HasError() == false)
            {
                for(size_t i = 0; i < value.GetNumArrayValues(); ++i)
                {
                    const Pylon::DataProcessing::CVariant positions_pxValue = value.GetArrayValue(i);
                    if (positions_pxValue.HasError() == false)
                    {
                        positions_px.push_back(positions_pxValue.ToPointF2D());
                    }
                    else
                    {
                        hasError = true;
                        errorMessage = value.GetErrorDescription();
                        break;
                    }
                }
            }
            else
            {
                hasError = true;
                errorMessage = value.GetErrorDescription();
            }
        }

        // Scores
        auto posScores = variantContainer.find("Scores");
        if (posScores != variantContainer.end())
        {
            const Pylon::DataProcessing::CVariant& value = posScores->second;
            if (value.HasError() == false)
            {
                for(size_t i = 0; i < value.GetNumArrayValues(); ++i)
                {
                    const Pylon::DataProcessing::CVariant scoresValue = value.GetArrayValue(i);
                    if (scoresValue.HasError() == false)
                    {
                        scores.push_back(scoresValue.ToDouble());
                    }
                    else
                    {
                        hasError = true;
                        errorMessage = value.GetErrorDescription();
                        break;
                    }
                }
            }
            else
            {
                hasError = true;
                errorMessage = value.GetErrorDescription();
            }
        }

        // Texts
        auto posTexts = variantContainer.find("Texts");
        if (posTexts != variantContainer.end())
        {
            const Pylon::DataProcessing::CVariant& value = posTexts->second;
            if (value.HasError() == false)
            {
                for(size_t i = 0; i < value.GetNumArrayValues(); ++i)
                {
                    const Pylon::DataProcessing::CVariant textsValue = value.GetArrayValue(i);
                    if (textsValue.HasError() == false)
                    {
                        texts.push_back(textsValue.ToString());
                    }
                    else
                    {
                        hasError = true;
                        errorMessage = value.GetErrorDescription();
                        break;
                    }
                }
            }
            else
            {
                hasError = true;
                errorMessage = value.GetErrorDescription();
            }
        }

        // Texts2
        auto posTexts2 = variantContainer.find("Texts2");
        if (posTexts2 != variantContainer.end())
        {
            const Pylon::DataProcessing::CVariant& value = posTexts2->second;
            if (value.HasError() == false)
            {
                for(size_t i = 0; i < value.GetNumArrayValues(); ++i)
                {
                    const Pylon::DataProcessing::CVariant texts2Value = value.GetArrayValue(i);
                    if (texts2Value.HasError() == false)
                    {
                        texts2.push_back(texts2Value.ToString());
                    }
                    else
                    {
                        hasError = true;
                        errorMessage = value.GetErrorDescription();
                        break;
                    }
                }
            }
            else
            {
                hasError = true;
                errorMessage = value.GetErrorDescription();
            }
        }

    }
};