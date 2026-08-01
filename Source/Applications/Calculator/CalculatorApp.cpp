#include "CalculatorApp.h"

#include "../../../ThirdParty/imgui/imgui.h"

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

CalculatorApp::CalculatorApp()

    :

    Application("Calculator"),

    window(
        "Calculator",
        500,
        180,
        300,
        420
    )

{

}

void CalculatorApp::AddButton(
    const char* text,
    float width,
    float height
)
{
    if(ImGui::Button(text, ImVec2(width, height)))
    {
        std::string value = text;

        if(value == "C")
        {
            expression[0] = '\0';

            first = 0;

            operation = 0;

            waitingSecond = false;

            return;
        }

        if(value=="+" ||
           value=="-" ||
           value=="*" ||
           value=="/")
        {
            if(strlen(expression) > 0)
            {
                first = atof(expression);

                operation = value[0];

                expression[0] = '\0';

                waitingSecond = true;
            }

            return;
        }

        if(value == "=")
        {
            if(waitingSecond &&
               strlen(expression) > 0)
            {
                double second =
                    atof(expression);

                double result =
                    engine.Calculate(
                        first,
                        second,
                        operation
                    );

                snprintf(
                    expression,
                    sizeof(expression),
                    "%.10g",
                    result
                );

                waitingSecond = false;
            }

            return;
        }

        strncat(
            expression,
            value.c_str(),
            sizeof(expression) -
            strlen(expression) - 1
        );
    }
}

void CalculatorApp::Draw()
{
    if(!window.Begin())
        return;

    ImGui::PushStyleVar(
        ImGuiStyleVar_FrameRounding,
        12.0f
    );

    ImGui::PushStyleVar(
        ImGuiStyleVar_FramePadding,
        ImVec2(8,8)
    );

    //-------------------------------------------------
    // Display
    //-------------------------------------------------

    float displayHeight =
        ImGui::GetContentRegionAvail().y * 0.18f;

    ImGui::PushStyleVar(
        ImGuiStyleVar_FramePadding,
        ImVec2(
            10,
            std::min(displayHeight * 0.35f, 20.0f)
        )
    );

    ImGui::SetWindowFontScale(1.5f);

    ImGui::SetNextItemWidth(-1);

    ImGui::InputText(
        "##display",
        expression,
        sizeof(expression),
        ImGuiInputTextFlags_ReadOnly
    );

    ImGui::SetWindowFontScale(1.0f);

    ImGui::PopStyleVar();

    ImGui::Dummy(ImVec2(0,10));

    //-------------------------------------------------
    // Button Size
    //-------------------------------------------------

    float spacing =
        ImGui::GetStyle().ItemSpacing.x;

    float buttonWidth =
        (ImGui::GetContentRegionAvail().x -
        spacing * 3.0f) / 4.0f;

    float availableHeight =
        ImGui::GetContentRegionAvail().y;

    float buttonHeight =
        (availableHeight -
        spacing * 3.0f) / 4.0f;

    float size =
        std::min(
            buttonWidth,
            buttonHeight
        );

    buttonWidth = size;
    buttonHeight = size;

    float totalWidth =
        buttonWidth * 4 +
        spacing * 3;

    float offset =
        (ImGui::GetContentRegionAvail().x -
        totalWidth) * 0.5f;

    const char* buttons[4][4] =
    {
        {"7","8","9","/"},
        {"4","5","6","*"},
        {"1","2","3","-"},
        {"C","0","=","+"}
    };

    //-------------------------------------------------
    // Draw Buttons
    //-------------------------------------------------

    for(int row = 0; row < 4; row++)
    {
        if(offset > 0)
        {
            ImGui::SetCursorPosX(
                ImGui::GetCursorPosX() + offset
            );
        }

        for(int col = 0; col < 4; col++)
        {
            AddButton(
                buttons[row][col],
                buttonWidth,
                buttonHeight
            );

            if(col < 3)
            {
                ImGui::SameLine();
            }
        }
    }

    ImGui::PopStyleVar(2);

    window.End();
}
