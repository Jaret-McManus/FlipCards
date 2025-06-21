#include "MyApp.h"
#include "imgui.h"

namespace MyApp {
    void RenderUI()
    {
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);


        SetAppStyleVar();
        ImGui::Begin("MyApp", false, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize);

        RenderSideBar();
        ImGui::SameLine();
        RenderContentSection();


        ImGui::End();
        ImGui::PopStyleVar();
    }

    void RenderSideBar()
    {
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(1, 1, 1, 1));
        ImGui::BeginChild("Sidebar", ImVec2(200, -1));
        {

            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 0, 0, 1));
            ImGui::Text("SideBar");

            const int bottomBtnSize = 30;
            ImVec2 bottomPos = ImVec2(
                ImGui::GetCursorPos().x,
                ImGui::GetWindowSize().y - bottomBtnSize
            );
            ImGui::SetCursorPos(bottomPos);
            ImGui::Button("Hi");

            ImGui::PopStyleColor();
        }
        ImGui::EndChild();
        ImGui::PopStyleColor();
    }

    void RenderContentSection()
    {
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.565f, 0.835f, 255.0f, 1.0f));
        ImGui::BeginChild("Content", ImVec2(-1, -1));
        {
            ImGui::Text("Main section");
        }
        ImGui::EndChild();
        ImGui::PopStyleColor();
    }

    void SetAppStyleVar()
    {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    }

    void PopAppStyleVar()
    {
        for (int i = 0; i < 1; i++)
        {
            ImGui::PopStyleVar();
        }
    }
}
